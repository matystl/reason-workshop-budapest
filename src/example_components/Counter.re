[@react.component]
let make = () => {
  let (counter, setCounter) = React.useState(() => 0);
  let onClick = _e => setCounter(state => state + 1);
  <div>
    {React.string("Here is counter:" ++ string_of_int(counter))}
    <button onClick> {React.string("Inc")} </button>
  </div>;
};