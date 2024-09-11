-compile(export_all). % testing-phase directive



-spec min_bit_flips(Start :: integer(), Goal :: integer()) -> integer().

min_flips(A, B, Res) when (A bor B) =/= 0 ->
	min_flips((A bsr 1), (B bsr 1), Res + (1 band (A bxor B)));
min_flips(A, B, Res) -> Res.

min_bit_flips(Start, Goal) -> min_flips(Start, Goal, 0).
