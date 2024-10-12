%% -module(sol).
-compile(export_all). % testing phase directive
-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"

-spec min_groups(Intervals :: [[integer()]]) -> integer().

sign(0) -> 0;
sign(X) when X < 0 -> -1;
sign(_) -> 1.

rx(Intervals) ->
    element(1, lists:foldl(fun(E, {A, B}) -> {max(A, B + sign(E)), B + sign(E)} end,
						   {0, 0}, lists:sort(fun(A, B) ->
													  case abs(A) =:= abs(B) of
														  true -> A >= B;
														  false -> abs(A) < abs(B)
													  end
											  end,
											  lists:flatmap(fun([First, Rest]) -> [First, -Rest] end, Intervals)))).

min_groups(Intervals) -> rx(Intervals).
