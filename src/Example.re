type state = {isPlaying: bool};

type action =
  | TogglePlay;

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | TogglePlay => {...state, isPlaying: !state.isPlaying}
        },
      {isPlaying: false},
    );
  <>
    <div> {ReasonReact.string("Muzik")} </div>
    <button onClick={_ => dispatch(TogglePlay)} />
    {state.isPlaying ? <Sound /> : ReasonReact.null}
  </>;
};