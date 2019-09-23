/* BASIC TYPES */

true; // bool
5; // int
2.3; // float
(); // unit
"Hello Budapest"; // string

"Strings are by default
multiline";

{| Alternative way to write strings. No need to escape " |};

{whatever| You can choose your own delimiter to avoid escaping problems.
 {| Look ma no escaping neded |}  |whatever};

{js| js delimiter has special meaning that you can use unicode
 characters inside 😀 |js};

/* BASIC OPERATIONS */

/* ARITMETIC */

10 + 2;
10 - 2;
10 * 2;
10 / 3;

// floats have their own version with dot
10.0 +. 2.0;
10.0 -. 2.0;
10.0 *. 2.0;
10.0 /. 3.0;

// comparison operator is universal
// < > <= >= == !=
// === is referential equality and usually you don't want that
1 < 2;
1.0 < 2.0;
"a" < "b";
// but no mixing of types
//"a" < 1;
//1 < 2.0;

// string concatenation
"Hello " ++ "world";
// and conversion of values to string
string_of_bool(true);
string_of_int(15);

// you can guess other conversion functions
float_of_int(4) /. 2.;

// basic boolean operators
!true && false || true;

// infix function can be called like normal functions if you put it into brackets
// but rfmt might change it anyway
// (+)(1,2);

/* VARIABLES AND BASIC FUNCTIONS */
let someVarialbeName = 5;
// you can add type manualy but they are inferred anyway
let otherVariableName: int = 5;
// you can type any expression with parentheses (but rfmt will sometimes mingle with it)
//let otherVariableName2 = (5: int);

// types are usually not needed as they are inferred for almost anything
let f = (a, b) => a + b;
// but you can specify them
let f2 = (a: int, b: int): int => a + b;
let f3: (int, int) => int = (a, b) => a + b;

// functions are first class object
// you can take them as arguments
let applyFunctionOverValue = (f, v) => f(v);
let inc = x => x + 1;
applyFunctionOverValue(inc, 5) /* or return them as value*/;

// instead of one value you can use block
let functionWithBlock = (a, b) => {
  // last value is returned automatically
  a + b;
};

// you can use block anywhere expression is expected
let varialbeDeclaredWithBlock = {
  let x = 5;
  let y = 10;
  // last value is returned autmaticaly
  x * y;
};

// COMPOSITE DATA TYPES

// tupples - immutable, fix-sized, heterogenous
let a3 = (1, "2");
// you can destructure them
let (xx, _, yy) = ("my string", 9, " other string");
// usefull for returning multiple values from functions

// list - immutable, homogeneous
let firstList = [1, 2];
// you can append to it by using spread operator
let secondList = [3, ...firstList];

// array - mutable, fixed size(on js side they have variable size)
let firstArray = [|1, 2, 3|];
firstArray[0] = 15;

// records - immutable by default, fixed set of fields
type person = {
  name: string,
  age: int,
};

// types are inferred automaticaly
let oldJohn = {name: "John", age: 70};
// to access fields use dot operator
oldJohn.name;

// type inference works even in function definition
let greetPerson = p => print_string("Hello " ++ p.name);

// you can spread to create modified record
let littleJohn = {...oldJohn, age: 5};

/* name punning */
let middleJohn = {
  // notice that first curly brace indicates start of block, not record
  let age = 20;
  // {...oldJohn, age: age};
  {...oldJohn, age};
};

// JAVASCRIPT OBJECTS

// no need to define types
let firstJsObject = {"name": "maty", "age": 15};
// to access properties you need to use ## instead of . as in records
firstJsObject##name;

// but you can define it if you want
type someJsObjectType = {
  .
  "name": string,
  "age": int,
};
let secondJsObject: someJsObjectType = {"name": "maty", "age": 15};

// VARIANTS

// mutually exclusive states
// type validity = Valid | Invalid;
type validity =
  | Valid
  | Invalid;

let validityOfConnection = Valid;

type point = (int, int);

// variants can have inner data
type shape =
  | Circle(point, int)
  | Square(point, point);

let someShape = Circle((15, 4), 10);

// maybe we should create record for each shape
type circle = {
  center: point,
  radius: int,
};
type square = {
  topLeft: point,
  bottomRight: point,
};
// you might want to do simple union but every option of variant has to have name
//type betterShape = circle | square
type betterShape =
  | Circle(circle)
  | Square(square);

let myCircle = {center: (10, 10), radius: 10};
let mySquare = {topLeft: (10, 10), bottomRight: (50, 50)};
let someBetterShape = Circle(myCircle);
let otherBetterShape = Square(mySquare);

// POLYMORFIC VARIANT TYPES

// similar to normal variants but no need to define them
// and also they are existing as globals

// problem with reusing same variant in multiple types
type colorLightEnum =
  | Red
  | Blue
  | Orange;
type colorDarkEnum =
  | Red
  | Yellow
  | Green;
let colorOfShape = Red;
//(colorOfShape: colorLightEnum);
(colorOfShape: colorDarkEnum);

// lets try same thing with polymorfic variant
let colorOfShape = `Red;

type colorLightEnum1 = [ | `Red | `Blue | `Orange];
(colorOfShape: colorLightEnum1);
type colorDarkEnum1 = [ | `Red | `Yellow | `Green];
(colorOfShape: colorLightEnum1);

// as `Red exist as global it can participate in multiple unions

// OPTION most used variant

// already defined no need to do it yourself
// type option('a) =
//   | Some('a)
//   | None;

let maybeIntValue = Some(5);
let maybeNotIntValue = None;

let a =
  switch (maybeIntValue) {
  | Some(i) => i * 10
  | None => 0
  };

type direction =
  | Up(int)
  | Left(int);

let originalPoint = (5, 5);
let movement = Up(5);

let movePoint = (point, movement) =>
  switch (movement) {
  | Up(u) =>
    let (x, y) = point;
    (x + u, y);
  | Left(l) =>
    let (x, y) = point;
    (x, y + l);
  };

let movedPoint = movePoint(originalPoint, movement);

// FUNCTIONS WITH NAMED ARGUMENTs

let functionWithNamedArgumens = (positionalArgument, ~namedArgument) =>
  positionalArgument + namedArgument;

let result1 = functionWithNamedArgumens(1, ~namedArgument=2);
let namedArgument = 4;
//
// let result2 = functionWithNamedArgumens(1, ~namedArgument=namedArgument);
let result3 = functionWithNamedArgumens(1, ~namedArgument);

// FUNCTIONS WITH NAMED(DEFAULT/OPTIONAL) ARGUMENTs

let functionWithDefault = (~namedWithDefault="5", positionalArgument) =>
  positionalArgument ++ namedWithDefault;

functionWithDefault("positionalValue");
functionWithDefault(~namedWithDefault="namedValue", "positionalValue");
functionWithDefault("positionalValue", ~namedWithDefault="namedValue");
// But when there is no positional argument last argument must be unit
let functionWithOnlyDefaultNamedArgument = (~a="a", ~b="b", ()) =>
  "hello" ++ a ++ b;
let fwoda = functionWithOnlyDefaultNamedArgument();
let fwoda1 = functionWithOnlyDefaultNamedArgument(~a="aa", ());
let fwoda2 = functionWithOnlyDefaultNamedArgument(~b="bb", ());

/* MODULES */

// are used to organize code and provide namespacing
// module name must start with Uppercase letter
// every file is module with name same as filename
// directory structure is irrelevant
// to use anything from module just mention it by name
// Ctrl+click will take you to the module

/* Nested modules */

module Nested = {
  let varInNestedModule = 5;
  module InnerNested = {
    let varInDoubleNestedModule = 7;
  };
};
let x = Nested.varInNestedModule + Nested.InnerNested.varInDoubleNestedModule;

// Sometimes it is usefull to bring whole namespace into current block/whole file
let var = {
  // open Nested;
  // x + InnerNested.y;
  Nested.(
    varInNestedModule + InnerNested.varInDoubleNestedModule
  );
};

/* STD lib */

// reason when used with bucklescript has 3 standart libraries

// ocaml one https://reasonml.github.io/api/index
Array.map(x => x + 1, [|1, 2, 3|]);

// javascript one https://bucklescript.github.io/bucklescript/api/Js.html
Js.Array.map(x => x + 1, [|1, 2, 3|]);

// bucklescript one https://bucklescript.github.io/bucklescript/api/Belt.html
Belt.Array.map([|1, 2, 3|], x => x + 1);

// docs to first 2 are in ocaml so use this https://reasonml.github.io/en/try
// to translate ocaml to reason

// my recommendation is to use Belt with fast pipe

/* FAST PIPE | PIPE LAST */
let myArray = [|1, 2, 3, 4, 5, 6|];

Belt.Array.map(Belt.Array.keep(myArray, x => x / 2 == 0), x => x * 2);

// or you can pipe result of previous operation into next operation and restore natural order
myArray->Belt.Array.keep(x => x / 2 == 0)->Belt.Array.map(x => x * 2);

/* curry-ing */

// there is similar thing for 'piping' last arguments

// it is sometimes helpful for Js module or ocaml library
myArray |> Js.Array.filter(x => x / 2 != 0) |> Js.Array.map(x => x * 2);