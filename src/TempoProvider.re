type tempoValue = {tempo: float};

let tempoContext = React.createContext({tempo: 120.}: tempoValue);

let makeProps = (~value: tempoValue, ~children, ()) => {
  "value": value,
  "children": children,
};

let make = React.Context.provider(tempoContext);