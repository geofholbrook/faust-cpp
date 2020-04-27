import("stdfaust.lib");

reverb_wetdry(sig, wd) = (sig * (1-wd)) + ((sig : re.mono_freeverb(.9,.5,.3,1)) * wd);
										 								 
signal = (ba.pulsen(1,4410*8) + ba.pulsen(1,4410*1.3)) : pm.djembe(60,0.5,0.5,1);

wetdry = nentry("wetdry",0.1,0,1,0.01);

process = reverb_wetdry(signal, 0.1);										 