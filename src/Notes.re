type note = [ | `c3 | `d3 | `e3 | `f3 | `g3 | `a3 | `h3 | `c4];

let frequencyFromNote = note =>
  switch (note) {
  | `c3 => 130.81
  | `d3 => 146.83
  | `e3 => 164.81
  | `f3 => 174.61
  | `g3 => 196.00
  | `a3 => 220.00
  | `h3 => 246.94
  | `c4 => 261.63
  };