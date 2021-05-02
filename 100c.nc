(100)
(testcnc222)
(T1  D=2.5 CR=0 - ZMIN=-11 - flat end mill)
G90 G94
G17
G21
G28 G91 Z0
G90

(Drill1)
T1
S5000 M3
G54
G0 X67.175 Y-67.175
Z13
Z5
Z4
G1 Z-11 F333.3
G0 Z5
X0 Y-95
Z4
G1 Z-11 F333.3
G0 Z5
X-67.175 Y-67.175
Z4
G1 Z-11 F333.3
G0 Z5
X-95 Y0
Z4
G1 Z-11 F333.3
G0 Z5
X-67.175 Y67.175
Z4
G1 Z-11 F333.3
G0 Z5
X0 Y95
Z4
G1 Z-11 F333.3
G0 Z5
X67.175 Y67.175
Z4
G1 Z-11 F333.3
G0 Z5
X95 Y0
Z4
G1 Z-11 F333.3
G0 Z5
X0
Z4
G1 Z-11 F333.3
G0 Z5
Z13
(When using Fusion 360 for Personal Use, the feedrate of )
(rapid moves is reduced to match the feedrate of cutting )
(moves, which can increase machining time. Unrestricted )
(rapid moves are available with a Fusion 360 Subscription. )

(2D Contour1)
X139.5 Y0.25
G1 Z13 F500
Z7
Z-5.75 F100
G18 G3 X139.25 Z-6 I-0.25 K0 F500
G1 X139
G17 G3 X138.75 Y0 I0 J-0.25
G2 X-138.75 Y0 I-138.75 J0
X138.75 Y0 I138.75 J0
G3 X139 Y-0.25 I0.25 J0
G1 X139.25
G18 G2 X139.5 Z-5.75 I0 K0.25
G1 Z5
Y0.25
Z1 F100
Z-10.75
G3 X139.25 Z-11 I-0.25 K0 F500
G1 X139
G17 G3 X138.75 Y0 I0 J-0.25
G2 X-138.75 Y0 I-138.75 J0
X138.75 Y0 I138.75 J0
G3 X139 Y-0.25 I0.25 J0
G1 X139.25
G18 G2 X139.5 Z-10.75 I0 K0.25
G1 Z13
G17
G28 G91 Z0
G90
G28 G91 X0 Y0
G90
M5
M30
