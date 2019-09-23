module Nested = {
  [@react.component]
  let make = () => <div> {React.string("nested component")} </div>;
};

[@react.component]
let make = () =>
  <div>
    {React.string("parrent start >>>")}
    <Nested />
    {React.string("parrent end <<<")}
  </div>;