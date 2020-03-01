Find negative cycles
------------------
<br> Input
<br> - file with graph in GraphViz style
<br> Output
<br> - image with founded negative cycles
<br> Example:
<br>![Image alt](https://github.com/Nikitasobakabmx/CycleofNegativeCost/raw/master/example/test.png)

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
