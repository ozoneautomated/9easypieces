void spin(long howlong) {
	long t = time(0);
	while ( (time(0) - t) < howlong)
	;
}
