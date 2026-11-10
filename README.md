# TB Digital Multi Echo — modern Mac version

The same plugin as [TB-Digital-Multi-Echo](https://github.com/tonybuzzcock/TB-Digital-Multi-Echo)
(same H/H Digital Multi-Echo model, panel and presets), built for current Macs:

- **CLAP, VST3 and AU (AUv2)**: Reaper, FL Studio, Logic, GarageBand, Ableton Live and others
- **Universal**: native on Apple Silicon and Intel, **macOS 11 Big Sur and later**
- Built and tested on GitHub Actions, including Apple's `auval`, `pluginval` and `clap-validator`
- Use it as an insert, or as a send/return effect with **Dry** out
- Personal, non-commercial use

The plugin is written once as a CLAP (`Source/Plugin`); [clap-wrapper](https://github.com/free-audio/clap-wrapper)
builds the VST3 and AU from the same code, so all three behave identically.
Settings are saved with your DAW session, and the plugin reports its latency
(40 samples) and a tail for the repeats and reverb.

## Install

Download the latest green run under **Actions → Artifacts → TB-Digital-Multi-Echo-mac**
(or a Release), unzip it, and follow `INSTALL.txt`: copy the formats you want into
`~/Library/Audio/Plug-Ins/VST3`, `.../Components` or `.../CLAP`, then run the one
Terminal command it gives to clear macOS's download quarantine (the plugins are
ad-hoc signed, not notarised).

## Controls

| # | Name | Control | Range |
|---|------|---------|-------|
| 1 | Volume 1 | Channel 1 volume (left input) | 0 – 10 |
| 2 | Volume 2 | Channel 2 volume (right input) | 0 – 10 |
| 3 | Reverb | Spring reverb level | 0 – 10 |
| 4 | Echo Volume | Echo level; 0 is ECHO OFF | 0 – 10 |
| 5 | Repeat Volume | Repeat level (feedback): runs away at 10 | 0 – 10 |
| 6–7 | Bass, Treble | Tone of the echo | 5 – 0 – 5 |
| 8–9 | Input 1/2 Echo | The Echo switch beside each input: sends that channel to the echo and reverb | On / Off |
| 10–13 | Echo 1–4 | Which taps you hear, any combination | In / Out |
| 14–17 | Repeat A–D | Which taps feed back, any combination | In / Out |
| 18 | Echo Rate | *plugin only*: the delay board's clock, shown as the longest tap (Echo 4) | 600 – 150 ms |
| 19 | Footswitch Echo | *plugin only*: echo on/off | On / Off |
| 20 | Footswitch Reverb | *plugin only*: reverb on/off | On / Off |
| 21 | Dry | *plugin only*: dry signal; Out for send/return use | In / Out |
| 22 | Output | *plugin only*: output trim | ±24 dB |

The left input is Channel 1 and the right input is Channel 2; the unit's one
output goes to both sides. Volume 2 starts at 0, so a mono track goes through
Channel 1 only.

## The panel

1200 × 440, laid out like the unit: the knob row (Volume, Volume, Reverb, Echo
Volume, Repeat Volume, Bass, Treble) with gold caps and dark grey knurled skirts,
and the lower rail with the input jacks and their Echo switches, the ECHO 1–4 and
REPEAT A–D push buttons (ECHO glows bright red when in, dark red when out;
REPEAT glows light grey when in, black when out), the output jacks and the
Overload lamp. The strip along the bottom has the TB Electronic mark, Echo Rate,
the footswitch rockers, Dry, Output, the presets and the readout.

Drag knobs up/down (hold Shift for fine control), double-click a knob to reset
it, or use the scroll wheel. Click a button or slide switch to toggle it.
Rocker switches: press the top half for On/In, the bottom half for Off/Out.

**Presets:** click SAVE, then a slot 1–8. Click a saved slot to recall it; the
slot in use lights orange. Presets are shared by every instance and all three
formats, in `~/Library/Application Support/TB/TB Digital Multi Echo/Presets.txt`.

## What's modelled

See [TB-Digital-Multi-Echo](https://github.com/tonybuzzcock/TB-Digital-Multi-Echo)
for the full notes: the circuit from drawing C/AC20031 (input channels,
pre-emphasis, the 36 dB anti-alias and reconstruction filters, the ECHO and
REPEAT banks, repeat filter, de-emphasis, the signal programmed output switch,
tone circuit, spring reverb and output mixer), plus estimates for the sealed
delay board (tap times, converter) and the values the drawing doesn't fix.

## Build and test

```
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
build/multiecho_test renders && build/preset_test
build/clap_host_test "build/plugins/TB Digital Multi Echo.clap/Contents/MacOS/TB Digital Multi Echo"
```

On Linux only the CLAP and the tests build (the CLAP binary is then
`build/plugins/TB Digital Multi Echo.clap`).
