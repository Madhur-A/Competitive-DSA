%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec car_fleet(Target :: integer(), Position :: [integer()], Speed :: [integer()]) -> integer().

rx(Positions, Speeds, Target) ->
    element(1, lists:foldl(fun({Distance, Speed}, {Res, PrevTime}) ->
                                   CurrentTime = (Target - Distance) / Speed,
                                   case CurrentTime > PrevTime of
                                       true  -> {Res + 1, CurrentTime};
                                       false -> {Res, PrevTime}
                                   end
                           end, {0, 0.0}, lists:reverse(lists:sort(lists:zip(Positions, Speeds))))).

car_fleet(Target, Position, Speed) -> rx(Position, Speed, Target).
