[@react.component]
let make = () => {
  let (text, setText) = React.useState(() => "");
  let onChange = e => setText(e->ReactEvent.Form.target##value);
  <div> <input value=text onChange /> </div>;
};