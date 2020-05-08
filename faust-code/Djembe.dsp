import("stdfaust.lib");

periodms = nentry("period",1000,50,2000,10);
freq = nentry("freq",100, 20, 10000, 1);
strikePosition = nentry("strikePosition", .5, 0, 1, 0.01);
strikeSharpness = nentry("strikeSharpness", .5, 0, 1, 0.01);
gain = nentry("gain", 1, 0, 5, 0.1);

// periodms = 1000;

process = ba.pulsen(100,periodms * 44.1) : pm.djembe(freq, strikePosition, strikeSharpness, gain);
