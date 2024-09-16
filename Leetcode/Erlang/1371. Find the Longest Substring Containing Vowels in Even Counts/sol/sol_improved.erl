%% -module(sol_improved). % this is faster, but not strictly functional
-compile(export_all). % testing phase directive
-author("nishizumi").

%% -spec find_the_longest_substring(S :: unicode:unicode_binary()) -> integer().
-spec find_the_longest_substring(S :: string()) -> integer().

all_vowels([], _, D) -> D;
all_vowels([First|Rest], I, D) -> all_vowels(Rest, I + 1, dict:append(First, I, D)).

get_vowels() -> all_vowels("aeiou", 0, dict:new()).

all_states(0, States) -> array:set(0, -1, States);
all_states(N, States) -> all_states(N-1, array:set(N, 1 bsl 40, States)).

contains(E, D) ->
	case dict:find(E, D) of
		error -> -1;
		{ok, F} -> hd(F)
	end.

next_state(State, Char, V) ->
	case contains(Char, V) of
		-1 -> State;
		F -> State bxor (1 bsl F)
	end.

process_string([], _, _, _, _, Res) -> Res;
process_string([Char|Rest], Index, State, V, Positions, Res) ->
	NewState = next_state(State, Char, V),
	NewRes = max(Res, Index - array:get(NewState, Positions)),
	NewPosition = array:set(NewState, min(array:get(NewState, Positions), Index), Positions),
	process_string(Rest, Index + 1, NewState, V, NewPosition, NewRes).

find_the_longest_substring(S) ->
	process_string(binary_to_list(S), 0, 0, get_vowels(), all_states(31, array:new(32)), 0). %%

clear() ->
	io:format("\ec").
