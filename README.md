Find negative cycles
------------------
Input
<br> file with graph in GraphViz style
Output
<br> image with founded negative cycles
example:
[[image:example/test.png]]

input text:
<pre>
<code class="php">
digraph g {
	2 -> 4 [cost = -1, label = -1]
	4 -> 1 [cost = -1, label = -1]
	1 -> 2 [cost = -1, label = -1]
}

</code>
</pre>
Output: 
<pre>
<code class="php">
digraph g {
	2 -> 4 [cost = -1, label = -1]
	4 -> 1 [cost = -1, label = -1]
	1 -> 2 [cost = -1, label = -1]
}
</code>
</pre>
