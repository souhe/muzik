[@react.component]
let make = (~freq: float=420., ~delay: float=0., ~duration=1.) => {
  React.useEffect(() => {
    open Audio;
    let audioContext = make(~options=None);
    let oscillator = audioContext->createOsc;
    let destination = audioContext->destinationGet;

    oscillator->frequency->setValueAtTime(freq, 0.);
    oscillator->connect(destination);
    oscillator->start(delay);
    oscillator->stop(duration +. delay);

    Some(() => oscillator->stop(0.));
  });

  ReasonReact.null;
};