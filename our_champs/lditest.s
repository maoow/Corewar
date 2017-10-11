.name        "lditest"
.comment    "lditest"

torpinit:
ld        %0, r2
ld        %4, r3
ld        %96, r5
sti        r1, %:torpwrite, %1
st        r1, 6

torpwrite:
torpl1:
live    %8008135
ldi        %:torpinit, r2, r4
sti        r4, %400, r2
add        r2, r3, r2
