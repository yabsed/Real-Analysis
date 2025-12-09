Here is a comprehensive, concise cheat sheet covering Sections 4.1 through 4.4.

---

# **Real Analysis Cheat Sheet: Limits & Continuity**

## **4.1 Limit of a Function**

### **1. Definitions**
* **$\epsilon-\delta$ Definition:** Let $(X, d)$ be a metric space, $E \subset X$, $f: E \to \mathbb{R}$, and $p$ a limit point of $E$.
    $$\lim_{x \to p} f(x) = L \iff \forall \epsilon > 0, \exists \delta > 0 \text{ s.t. } 0 < d(x, p) < \delta \implies |f(x) - L| < \epsilon$$
    * **Note:** $\delta$ depends on $\epsilon$ and $p$. $p$ need not be in $E$.
* **Sequential Criterion:** $\lim_{x \to p} f(x) = L \iff$ for every sequence $\{p_n\}$ in $E$ ($p_n \neq p$) with $p_n \to p$, the sequence $f(p_n) \to L$.
* **Limit at Infinity:** Let domain be unbounded. $\lim_{x \to \infty} f(x) = L$ if $\forall \epsilon > 0, \exists M \in \mathbb{R}$ such that $x > M \implies |f(x) - L| < \epsilon$.

### **2. Key Examples & Techniques**
* **Rational Functions:** $h(x) = \frac{\sqrt{x+1}-1}{x}$. Rationalize numerator to bound $|h(x) - 1/2|$.
* **Dirichlet Function:** $f(x) = 1$ if $x \in \mathbb{Q}$, $0$ if $x \notin \mathbb{Q}$. Limit exists **nowhere** (density of $\mathbb{Q}$ and $\mathbb{Q}^c$).
* **Modified Dirichlet:** $f(x) = x$ if $x \notin \mathbb{Q}$, $0$ if $x \in \mathbb{Q}$. Continuous **only at** $x=0$ (since $|f(x)| \le |x|$).
* **$1/x$ on $(0,1)$:** To show $\lim_{x \to p} 1/x = 1/p$, $\delta$ must shrink as $p \to 0$ ($\delta \approx p^2\epsilon$).
* **Multivariable:** $f(x,y) = \frac{xy}{x^2+y^2}$. Use Triangle Inequality and restrict to neighborhood (e.g., $N_{1/2}(p)$) to bound denominator.
* **Oscillation:** $\lim_{x \to 0} \sin(1/x)$ DNE. Sequence $p_n = \frac{2}{(2n+1)\pi}$ yields $(-1)^n$ (divergent).

### **3. Theorems**
* **Uniqueness:** If a limit exists, it is unique.
* **Algebra:** $\lim(f \pm g) = A \pm B$, $\lim(fg) = AB$, $\lim(f/g) = A/B$ ($B \neq 0$).
* **Boundedness Thm:** If $|g(x)| \le M$ and $\lim f(x) = 0 \implies \lim f(x)g(x) = 0$.
    * *Ex:* $\lim_{x \to 0} x \sin(1/x) = 0$.
* **Squeeze Thm:** $g \le f \le h$ and $\lim g = \lim h = L \implies \lim f = L$.
    * *App:* $\lim_{t \to 0} \frac{\sin t}{t} = 1$ (via geometry and squeeze: $\cos t < \frac{\sin t}{t} < \frac{1}{\cos t}$).

---

## **4.2 Continuous Functions**

### **1. Definitions**
* **Metric:** $f$ is continuous at $p \in E$ if $\forall \epsilon > 0, \exists \delta > 0$ s.t. $d(x, p) < \delta \implies |f(x) - f(p)| < \epsilon$.
* **Topological:** $f$ is continuous on $E \iff f^{-1}(V)$ is open in $E$ for every open set $V \subset \mathbb{R}$.
    * *Note:* Forward image of open set need not be open.
* **Sequential:** $p_n \to p \implies f(p_n) \to f(p)$.
* **Isolated Points:** Functions are always continuous at isolated points of $E$.

### **2. Classification of Examples**
* **Removable Discontinuity:** $\lim_{x \to p} f(x)$ exists but $\neq f(p)$.
    * *Ex:* $g(x) = \frac{x^2-4}{x-2}$ at $x=2$. Set $g(2)=4$ to fix.
* **Thomae’s Function (Popcorn):** $f(x) = 1/n$ if $x=m/n \in \mathbb{Q}$, $0$ if irrational.
    * Continuous at all **irrationals**.
    * Discontinuous at all **rationals**.
* **Sine:** $f(x) = \sin x$ continuous on $\mathbb{R}$ (Lipschitz with $K=1$).

### **3. Continuity & Compactness**
* **Preservation:** If $f$ is continuous and $K$ is compact, then $f(K)$ is compact.
* **Extreme Value Theorem:** If $K$ is compact (closed & bounded in $\mathbb{R}$), $f$ attains its **Maximum** and **Minimum** on $K$.
    * *Counter-ex:* $f(x) = x$ on $(0,1)$ (bounded but not closed) has no max/min.
    * *Counter-ex:* $f(x) = \frac{x^2}{1+x^2}$ on $[0, \infty)$ (closed but not bounded) has no max.

### **4. Intermediate Value Theorem (IVT)**
* **Theorem:** If $f:[a,b] \to \mathbb{R}$ is continuous and $f(a) < \gamma < f(b)$, then $\exists c \in (a,b)$ s.t. $f(c) = \gamma$.
* **Corollary:** Continuous image of an interval is an interval.
* **Fixed Point Thm:** Continuous $f:[0,1] \to [0,1]$ has $y$ s.t. $f(y)=y$. (Proof via $g(x) = f(x)-x$).
* **Roots:** $y^n = \gamma$ exists for $\gamma > 0$.

---

## **4.3 Uniform Continuity**

### **1. Definition**
* **Uniform Continuity:** $f: E \to \mathbb{R}$ is uniformly continuous if:
    $$\forall \epsilon > 0, \exists \delta > 0 \text{ s.t. } \forall x, y \in E, d(x, y) < \delta \implies |f(x) - f(y)| < \epsilon$$
* **Key Difference:** In pointwise, $\delta$ depends on $p$ ($\delta(\epsilon, p)$). In uniform, $\delta$ is independent of $p$ ($\delta(\epsilon)$).

### **2. Uniform Continuity Theorem**
* **Theorem 4.3.4:** If $K$ is **compact** and $f$ is continuous on $K \implies f$ is uniformly continuous on $K$.
* **Heine's Theorem:** Continuous function on $[a,b]$ is uniformly continuous.

### **3. Lipschitz Functions**
* **Def:** $|f(x) - f(y)| \le M d(x, y)$ for constant $M$.
* **Implication:** Lipschitz $\implies$ Uniformly Continuous (Take $\delta = \epsilon/M$).
    * *Note:* Converse is false (e.g., $\sqrt{x}$ on $[0,1]$ is unif. cont. but not Lipschitz).

### **4. Examples & Counter-Examples**
* **$f(x) = x^2$:**
    * On **Bounded** set $E$: **Uniform**. $|x^2-y^2| = |x+y||x-y| \le 2C|x-y|$.
    * On **Unbounded** (e.g., $[0, \infty)$): **Not Uniform**. Values grow too fast.
* **$f(x) = 1/x$:**
    * On $(0,1)$: **Not Uniform**. As $x \to 0$, slope $\to \infty$. $\delta$ cannot be constant.
    * On $[a, \infty)$ with $a>0$: **Uniform**.
* **$f(x) = \sin x$:** **Uniform** on $\mathbb{R}$ (bounded derivative).

---

## **4.4 Monotone Functions & Discontinuities**

### **1. One-Sided Limits**
* **Right Limit ($f(p+)$):** Limit as $x \to p$ with $x > p$.
* **Left Limit ($f(p-)$):** Limit as $x \to p$ with $x < p$.
* **Continuity:** $f$ is continuous at $p \iff f(p+) = f(p-) = f(p)$.

### **2. Classification of Discontinuities**
* **Simple (1st Kind):** Both $f(p+)$ and $f(p-)$ exist.
    * **Removable:** $f(p+) = f(p-) \neq f(p)$.
    * **Jump:** $f(p+) \neq f(p-)$.
        * *Ex:* $f(x) = [x]$ (Greatest Integer). Jump size 1 at integers.
* **Second Kind:** At least one of $f(p+)$ or $f(p-)$ does not exist.
    * *Ex:* $f(x) = \sin(1/x)$ at $x=0$.

### **3. Monotone Functions**
* **Properties:** Let $f$ be monotone increasing on $I$.
    * **Existence of Limits:** For any $p \in \text{Int}(I)$, $f(p-)$ and $f(p+)$ exist.
    * **Ordering:** $\sup_{x<p} f(x) = f(p-) \le f(p) \le f(p+) = \inf_{x>p} f(x)$.
    * **Interval Relation:** $p < q \implies f(p+) \le f(q-)$.
* **Corollary:** The set of discontinuities of a monotone function is **countable** (at most).

### **4. Construction of Discontinuities**
* **Unit Jump Function:** $I(x) = 0$ for $x<0$, $1$ for $x \ge 0$.
* **General Construction:** $f(x) = \sum_{n=1}^\infty c_n I(x - x_n)$ with $\sum c_n$ convergent.
    * $f$ is monotone increasing.
    * $f$ is discontinuous exactly at the countable set $\{x_n\}$.
    * Jump at $x_n$ is $f(x_n) - f(x_n-) = c_n$.
    * $f$ is continuous at $x \notin \{x_n\}$ and right-continuous everywhere.

### **5. Inverse Functions**
* **Theorem:** If $f: I \to \mathbb{R}$ is strictly monotone and continuous:
    1.  Image $J = f(I)$ is an interval.
    2.  Inverse $f^{-1}: J \to I$ exists.
    3.  $f^{-1}$ is **strictly monotone** and **continuous**.
* *Ex:* $f(x) = x^n$ on $[0, \infty) \implies \sqrt[n]{x}$ is continuous.