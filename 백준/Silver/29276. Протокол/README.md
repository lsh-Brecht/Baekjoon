# [Silver III] Протокол - 29276 

[문제 링크](https://www.acmicpc.net/problem/29276) 

### 성능 요약

메모리: 5940 KB, 시간: 12 ms

### 분류

그리디 알고리즘

### 제출 일자

2026년 2월 23일 17:46:35

### 문제 설명

<p>Во время соревнований Снежный Барс прогуливался по Сочи. На одной из ледовых арен он увидел пробные соревнования по фигурному баскетболу на лыжах с клюшками. Этот спорт планируют ввести к следующей олимпиаде. Там он увидел протокол некой команды-испытателей.</p>

<p>Протокол представлял собой таблицу из <mjx-container class="MathJax" jax="CHTML" style="font-size: 106.1%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> \times <mjx-container class="MathJax" jax="CHTML" style="font-size: 106.1%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$m$</span></mjx-container> символов. Причем каждый символ либо <<<code>+</code>>>, либо <<<code>-</code>>>, либо <<<code>?</code>>>. Барс никогда не видел таких протоколов, но, как ему объяснили, <<<code>+</code>>> обозначают число <<<code>+1</code>>>, а <<<code>-</code>>> --- <<<code>-1</code>>>. А сам результат команды --- разность суммы в строке с наибольшей суммой и суммы в столбце с наименьшей суммой. <<<code>?</code>>> означает, что в этом поле пока что ничего не стоит.</p>

<p>Барсу было лень разбираться в правилах, но ему стало интересно, какой максимальный результат сможет набрать команда к концу состязания, когда все <<<code>?</code>>> будут заменяны либо на <<<code>+</code>>>, либо на <<<code>-</code>>>. Он надеется, что вы сможете ему помочь и напишете программу, которая посчитает это для него. </p>

### 입력 

 <p>В первой строке дано два числа <mjx-container class="MathJax" jax="CHTML" style="font-size: 106.1%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> и <mjx-container class="MathJax" jax="CHTML" style="font-size: 106.1%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$m$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 106.1%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>n</mi><mo>,</mo><mi>m</mi><mo>≤</mo><mn>1000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le n, m \le 1000$</span></mjx-container>) --- количество строк и столбцов соответственно.</p>

<p>Далее идут <mjx-container class="MathJax" jax="CHTML" style="font-size: 106.1%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> строк по <mjx-container class="MathJax" jax="CHTML" style="font-size: 106.1%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45A TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>m</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$m$</span></mjx-container> символов, содержащие только <<<code>+</code>>>, <<<code>-</code>>> и <<<code>?</code>>>. </p>

### 출력 

 <p>В выходной файл должен содержать одно число  --- наибольший возможный результат, который в итоге может получить команда.</p>

