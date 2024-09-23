%% -module(sol).
-compile(export_all). % testing phase directive


% "Ooarai Joshigakuin Shori!"

%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec next_larger_nodes(Head :: #list_node{} | null) -> [integer()].

get_next(null,    _) -> [0];
get_next(Head, Curr) ->
		case Head#list_node.val > Curr of
			true -> [Head#list_node.val];
			false -> get_next(Head#list_node.next, Curr)
		end.


validate(null, _) -> [];
validate(Head, M) ->
	case Head#list_node.val < M of
		true -> [M] ++ validate(Head#list_node.next, M);
		false ->
			case Head#list_node.val =:= M of
				true -> [0] ++ validate(Head#list_node.next, 0);
				false ->
					[NewMax] = get_next(Head, Head#list_node.val),
					[NewMax] ++ validate(Head#list_node.next, NewMax)
			end
	end.


next_larger_nodes(Head) -> validate(Head, 0).
