%% -module(sol). % "Ooarai Joshigakuin Shori!"
-compile(export_all). % testing phase directive


%% -spec largest_number(Nums :: [integer()]) -> unicode:unicode_binary().

as_string([]) -> "";
as_string([First|Rest]) ->
	integer_to_list(First) ++ as_string(Rest).

get_largest(Nums) ->
	Res = as_string(lists:sort(fun(A, B) -> integer_to_list(A + B) < integer_to_list(B + A) end, Nums)),
	case hd(Res) =:= 48 of
		true  -> unicode:characters_to_binary("0");
		false -> unicode:characters_to_binary(Res)
	end.

largest_number(Nums) -> get_largest(Nums).

clear() ->
	io:format("\ec").
