%% -module(sol).
-compile(export_all). % testing phase directive
%% "Ooarai Joshigakuin Shori!"

-spec remove_nth_from_end(Head :: #list_node{} | null, N :: integer()) -> #list_node{} | null.

%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

hook(null) -> null;
hook(Sinker) ->
	case Sinker#list_node.next =/= null of
		true -> #list_node{val = Sinker#list_node.val, next = Sinker#list_node.next#list_node.next};
		false -> null
	end.

slow_tracker(SlowSinker,       null) -> hook(SlowSinker);
slow_tracker(SlowSinker, FastSinker) ->
	#list_node{val = SlowSinker#list_node.val, next = slow_tracker(SlowSinker#list_node.next, FastSinker#list_node.next)}.

fast_tracker(TrueSinker, Sinker, FCount, N) when FCount < N ->
	fast_tracker(TrueSinker, Sinker#list_node.next, FCount + 1, N);
fast_tracker(TrueSinker, Sinker, _, _) ->
	case Sinker =/= null of
		true -> slow_tracker(TrueSinker, Sinker#list_node.next);
		false  -> TrueSinker#list_node.next
	end.

tracker(Sinker, N) -> fast_tracker(Sinker, Sinker, 0, N).

remove_nth_from_end(Head, N) -> tracker(Head, N).
