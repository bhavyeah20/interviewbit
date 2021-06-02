bool seqMatch(strin a, string b) {
	return len(LCS(a, b)) == len(a);
}