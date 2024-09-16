%% -module(sol).
-compile(export_all). % testing phase directive


%% "Ooarai Joshigakuin Shori!"

%% -record(list_node, {val = 0 :: integer(), next = null :: 'null' | #list_node{}}).

swapper(null) -> null;
swapper(Node) when Node#list_node.next =:= null -> Node;
swapper(Node) -> swap_in_pair(Node, Node#list_node.next).

swap_in_pair(First, Second) ->
	#list_node{val = Second#list_node.val, next = #list_node{val = First#list_node.val, next = swapper(Second#list_node.next)}}.

swap_pairs(Head) -> swapper(Head).

clear() ->
	io:format("\ec").
