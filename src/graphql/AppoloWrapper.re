let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let httpLink =
  ApolloLinks.createHttpLink(
    //~uri="https://pokura.matystl.now.sh/api/graphql",
    ~uri="http://104.154.18.109/v1/graphql",
    (),
  );

let client =
  ReasonApollo.createApolloClient(~link=httpLink, ~cache=inMemoryCache, ());

[@react.component]
let make = () =>
  <ReasonApollo.Provider client>
    <ReasonApolloHooks.ApolloProvider client>
      <PokemonExample />
    </ReasonApolloHooks.ApolloProvider>
  </ReasonApollo.Provider>;