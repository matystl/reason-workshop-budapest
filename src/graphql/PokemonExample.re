module SimpleQueryText = [%graphql
  {|
query someRandomName {
    pokemon(limit: 2) {
        name
    }
}
|}
];

module SimpleQuery = ReasonApolloHooks.Query.Make(SimpleQueryText);

[@react.component]
let make = () => {
  let (simple, _full) = SimpleQuery.use();
  switch (simple) {
  | Data(data) =>
    Js.log(data##pokemon[0]##name);
    // use ->Belt.Array.map to render all returned pokemons
    // use ->React.Array to convert array to react element
    React.string("we have data");
  | Loading => React.string("loading")
  | NoData => React.string("noData")
  | Error(_) => React.string("error")
  };
};

/* For using variables in query

    - add variable to gql query string

   `query someRandomName($nameOfVariable: String!) {
      pokemon(limit:$nameOfVariable)
      ...
   `

    - and pass object with varialbes to hook

    let variables: Js.Json.t = {"nameOfVariable": "valueOfVariable"}->Obj.magic;
    let (simple, _full) = SimpleQuery.use(~variables, ());
    */