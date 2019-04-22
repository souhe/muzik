[@react.component]
let make = () => {
  React.useEffect(() => {
    open Audio;
    let audioContext = make(~options=None);
    let oscillator = createOsc(audioContext);
    let dest = audioContext->destinationGet;
    let amp = createAmp(audioContext);
    oscillator->connect(amp)->connect(dest);

    let currentTime: float = audioContext->currentTimeGet;
    (oscillator |> freq)->setValue(330., currentTime +. 3.5);
    oscillator->start(0.);
    Some(() => oscillator->stop(0.));
  });
  ReasonReact.null;
};