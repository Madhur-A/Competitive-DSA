%% -module(sol). % NOT functional
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shori!"

-spec knight_dialer(N :: integer()) -> integer().

% https://oeis.org/A327692
calculate(Index, N, Have) when Index =< N ->
    A = 6 * array:get(Index - 2, Have),
    B = 4 * array:get(Index - 4, Have),
    calculate(Index + 1, N, array:set(Index, A - B, Have));
calculate(_,     N, Have) -> array:get(N, Have).

knight_dialer(N) ->
    Have = array:from_list([0,10,20,46,104,240]),
    case N < 6 of
        true  -> array:get(N, Have);
        false -> calculate(6, N, Have) rem 1000000007
    end.
