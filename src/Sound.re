[@react.component]
let make = (~freq: float=420., ~delay: float=0.) => {
  React.useEffect(() => {
    open Audio;
    let audioContext = make(~options=None);
    let oscillator = createOsc(audioContext);
    let destination = audioContext->destinationGet;

    oscillator->frequency->setValueAtTime(freq, 0.);
    oscillator->connect(destination);
    oscillator->start(delay);

    Some(() => oscillator->stop(0.));
  });

  ReasonReact.null;
};