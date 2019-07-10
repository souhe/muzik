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
    <button onClick={_ => dispatch(TogglePlay)}>
      {ReasonReact.string("Play/Stop")}
    </button>
    {state.isPlaying
       ? <>
           <Sound freq=300. />
           <Sound freq=320. delay=1. />
           <Sound freq=340. delay=3. />
         </>
       : ReasonReact.null}
  </>;
};