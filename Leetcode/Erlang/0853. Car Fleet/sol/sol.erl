%% -module(sol).
-compile(export_all). % testing phase directive
-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"

-spec car_fleet(Target :: integer(), Position :: [integer()], Speed :: [integer()]) -> integer().

rx(Positions, Speeds, Target) ->
    	CurrentTarget = Target * 1.0,
        {Ans, _ } =
            lists:foldl(fun({Distance, Speed}, {Res, PrevTime}) ->
                                CurrentTime = (CurrentTarget - Distance) / Speed,
                                case CurrentTime > PrevTime of
                                    true  -> {Res + 1, CurrentTime};
                                    false -> {Res, PrevTime}
                                end
                            end, {0, 0.0}, lists:reverse(lists:sort(lists:zip(Positions, Speeds)))),
        Ans.

car_fleet(Target, Position, Speed) -> rx(Position, Speed, Target).
