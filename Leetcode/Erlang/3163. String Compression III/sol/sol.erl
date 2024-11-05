%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec compressed_string(Word :: unicode:unicode_binary()) -> unicode:unicode_binary().

repeat_times(0, _, Res) -> Res;
repeat_times(T, P, Res) ->
    repeat_times(T - 1, P, [P, 9 + $0] ++ Res).

calculate(Char, Count) when Count =< 9 ->
    [Char, Count + $0];
calculate(Char, Count) ->
    {Times, Left} = {Count div 9, Count rem 9},
    Repeated = repeat_times(Times, Char, []),
    case Left =:= 0 of
        true  -> Repeated;
        false -> [Char, Left + $0] ++ Repeated
    end.

rx([], Prev, Count, Res) -> calculate(Prev, Count) ++ Res;
rx([First | Rest], First, Count, Res) ->
    rx(Rest, First, Count + 1, Res);
rx([First | Rest], Prev, Count, Res) ->
    rx(Rest, First, 1, calculate(Prev, Count) ++ Res).

compressed_string(Word) ->
    S = binary:bin_to_list(Word),
    P = hd(S),
    binary:list_to_bin(lists:reverse(rx(S, P, 0, []))).
