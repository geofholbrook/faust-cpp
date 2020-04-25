import("stdfaust.lib");

signal = (os.osc(200 + os.osc(1) * 100) > os.osc(4)) * 1;

process = signal * (ba.pulsen(10, 44100 / 4) : en.adsre(0.01, 0.1, 0.5, 1));