[@react.component]
let make = () => {
  <div style={ReactDOMRe.Style.make(~color="green", ())}>
    {React.string("This component is styled with green text")}
  </div>;
};