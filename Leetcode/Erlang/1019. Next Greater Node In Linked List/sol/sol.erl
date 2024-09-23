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

validate(null) -> [];
validate(Head) -> get_next(Head, Head#list_node.val) ++ validate(Head#list_node.next).

next_larger_nodes(Head) -> validate(Head).
