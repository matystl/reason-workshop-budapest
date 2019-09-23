[%%debugger.chrome];

ReactDOMRe.renderToElementWithId(
  <Simple message="Hello budapest!" />,
  "index1",
);

ReactDOMRe.renderToElementWithId(<Counter />, "index2");

ReactDOMRe.renderToElementWithId(<Input />, "index3");

ReactDOMRe.renderToElementWithId(<ReduxReducer />, "index4");

ReactDOMRe.renderToElementWithId(<MoreInOneFile />, "index5");

ReactDOMRe.renderToElementWithId(<MoreInOneFile.Nested />, "index6");

ReactDOMRe.renderToElementWithId(<StyledComponent />, "index7");

ReactDOMRe.renderToElementWithId(<AppoloWrapper />, "index8");