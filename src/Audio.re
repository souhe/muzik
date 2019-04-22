module AudioNode = {
  type audio_node;
};

module AudioParam = {
  type audio_param;
  [@bs.send]
  external setValue: (audio_param, float, float) => unit = "setValueAtTime";
};

module AudioSourceNode = {
  include AudioNode;
  [@bs.send] external start: (audio_node, float) => unit = "start";
  [@bs.send] external stop: (audio_node, float) => unit = "stop";
};

module OscillatorNode = {
  include AudioSourceNode;
  [@bs.get] external freq: audio_node => AudioParam.audio_param = "frequency";
};

[@bs.deriving abstract]
type audio_context_options = {sampleRate: int};

type destination = AudioNode.audio_node;

[@bs.deriving abstract]
type audio_context = {
  baseLatency: float,
  currentTime: float,
  sampleRate: float,
  destination,
};

[@bs.new]
external _make: option(audio_context_options) => audio_context =
  "window.AudioContext";
[@bs.new]
external createOsc: audio_context => AudioSourceNode.audio_node =
  "window.OscillatorNode";
[@bs.new]
external createAmp: audio_context => AudioNode.audio_node = "window.GainNode";

[@bs.send]
external connect:
  (AudioNode.audio_node, AudioNode.audio_node) => AudioNode.audio_node =
  "connect";

let make = (~options) => _make(options);

let start = AudioSourceNode.start;
let stop = AudioSourceNode.stop;
let freq = OscillatorNode.freq;
let setValue = AudioParam.setValue;