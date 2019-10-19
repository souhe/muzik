type freq =
  | Frequency(float)
  | Note(Notes.note);

type time =
  | Sec(float)
  | Whole
  | Half
  | Quarter
  | Eighth
  | Sixteenth
  | ThirtySecond;

let timeToSec = (time, tempo: float) =>
  switch (time) {
  | Sec(x) => x
  | Whole => 1. /. (tempo /. 60.) *. 4.
  | Half => 1. /. (tempo /. 60.) *. 2.
  | Quarter => 1. /. (tempo /. 60.)
  | Eighth => 1. /. (tempo /. 60.) /. 2.
  | Sixteenth => 1. /. (tempo /. 60.) /. 4.
  | ThirtySecond => 1. /. (tempo /. 60.) /. 8.
  };

[@react.component]
let make = (~freq: freq, ~duration: time=Quarter, ~delay: time=Sec(0.)) => {
  let {tempo}: TempoProvider.tempoValue =
    React.useContext(TempoProvider.tempoContext);

  <Sound
    freq={
      switch (freq) {
      | Frequency(a) => a
      | Note(note) => Notes.frequencyFromNote(note)
      }
    }
    delay={timeToSec(delay, tempo)}
    duration={timeToSec(duration, tempo)}
  />;
};