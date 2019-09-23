- calculate average of 3 variables 
```
let v1=43242;
let v2=234;
let v3=4534;
```

- now make that result is float instead of integer

- create function that can calculate average of 3 arguments

- print some list, does it look different than you expected? Is is different than array? Can you convert list to array?

- Did you find out function Js.log2, Js.log3 try to use them.

- make some arguments of average function named

- make 2. argument optional 


- generalize avarage function to take list

- change average function to take array

- return from average tupple representing average and number of elements

- Declare some optional value and print it with switch. Then instead of switch try to use Belt.Option.getWithDefault

- find out how to define recursive functions and create ternary fibonaci
F_n = F_(n-1) + F_(n-2) + F_(n-3)

- create pokemon record: pokemon has name, height and mutlityple types(Electric,Water,...) modeled for begging as array of string (word type is reserved so its better to name that field as `kind` or if you like suffering `_type`, `type_`)

- try to print one pokemon does it look as you expected? What about when you try to use js obejcts(use apostrophs)
```
{
 "name": ...,
}
```

- change pokemon kinds(types) to variants

- define some array of pokemons(or google them) this will be our data to work on

- Print only water type of pokemons

- When printing don't relly on special Js.log smemantics but create strings from pokeomon and print only strings. (how do you convert variant to string?)

- put pokemon record definition and helper function into separate module.

- by convenience Pokemon module should have name record of pokemon as t, and expose make function.
```
module Pokemon = {
  type t = {
  }
  let make= (~name, ...):t => {
  }
  let to_string = (pokemon: t) =>
}
```

- compare how this pokemon module looks to Js.Date module. 
- try to use Js.Date module and what it actualy compiled as output


- PRO make last argument of average function optional and fix errors (remember unit as last example)

- PRO find out how to patterm match with switch on list variable when average function taked list as argument

- PRO-PRO make two functions that recursivly call each other