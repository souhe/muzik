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

  <TempoProvider value={tempo: 120.}>
    <div> {ReasonReact.string("Muzik")} </div>
    <button onClick={_ => dispatch(TogglePlay)}>
      {ReasonReact.string("Play/Stop")}
    </button>
    {state.isPlaying
       ? <>
           <Note freq={Note(`a3)} duration=Quarter />
           <Note freq={Note(`h3)} delay=Quarter duration=Quarter />
           <Note freq={Note(`c4)} delay=Quarter duration=Quarter />
           <Note freq={Note(`c3)} delay=Quarter duration=Quarter />
           <Note freq={Note(`e3)} delay=Quarter duration=Quarter />
         </>
       : ReasonReact.null}
  </TempoProvider>;
  // <Loop tempo=100. duration=4. playing={state.isPlaying}>
  //   {({clock}) =>
  //      <>
  //        <Delay clock duration=`quarter>
  //          <Note freq=`c />
  //          <Note freq=`e />
  //        </Delay>
  //        <Delay clock delay=`half duration=`sixteen>
  //          <Note freq=`g />
  //        </Delay>
  //      </>}
  // </Loop>
};