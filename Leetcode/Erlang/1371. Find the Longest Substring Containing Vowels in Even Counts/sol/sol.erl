%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec find_the_longest_substring(S :: string()) -> integer().

all_vowels(          [], _, D) -> D;
all_vowels([First|Rest], I, D) -> all_vowels(Rest, I + 1, dict:append(First, I, D)).

get_vowels() -> all_vowels("aeiou", 0, dict:new()).

has(E, D) ->
    case dict:find(E, D) of
        error -> 1 bsl 40;
        {ok, F} when is_list(F) -> hd(F);
        {ok, F} -> F
    end.

next_state(State, Char, V) ->
    case has(Char, V) of
        1 bsl 40 -> State;
        F -> State bxor (1 bsl F)
    end.

calculate_string(         [],     _,     _, _,         _, Res) -> Res;
calculate_string([Char|Rest], Index, State, V, Positions, Res) ->
    NewState = next_state(State, Char, V),
    NewRes = max(Res, Index - has(NewState, Positions)),
    calculate_string(Rest, Index + 1, NewState, V, dict:store(NewState, min(Index, has(NewState, Positions)), Positions), NewRes).

find_the_longest_substring(S) ->
    calculate_string(binary_to_list(S), 0, 0, get_vowels(), dict:store(0, -1, dict:new()), 0).

clear() ->
    io:format("\ec").
