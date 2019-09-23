[@react.component]
let make = (~message) =>
  <div> {React.string("This is component with message:" ++ message)} </div>;