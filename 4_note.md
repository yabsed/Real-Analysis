# **Chapter 4: Limits and Continuity**

### **1. The Limit of a Function**
The foundation of analysis on metric spaces.

* **Definition ($\epsilon-\delta$):**
    Let $(X, d_X)$ and $(Y, d_Y)$ be metric spaces, $E \subset X$, and $f: E \to Y$.
    $\lim_{x \to p} f(x) = L$ means:
    $$\forall \epsilon > 0, \exists \delta > 0 \text{ s.t. } 0 < d_X(x, p) < \delta \implies d_Y(f(x), L) < \epsilon$$
    *(Note: $p$ must be a limit point of $E$, but $p$ need not be in $E$.)*

* **Sequential Criterion:**
    $\lim_{x \to p} f(x) = L$ **if and only if** for every sequence $\{x_n\} \subset E$ with $x_n \neq p$ and $x_n \to p$, we have $\lim_{n \to \infty} f(x_n) = L$.

* **Algebra of Limits:**
    Limits respect addition, multiplication, and division (provided the denominator limit is non-zero).

---

### **2. Continuity**
Continuity bridges the topology of the domain to the topology of the range.

* **Pointwise Definition:**
    $f$ is **continuous at $p \in E$** if:
    $$\forall \epsilon > 0, \exists \delta > 0 \text{ s.t. } d_X(x, p) < \delta \implies d_Y(f(x), f(p)) < \epsilon$$
    *(Equivalently: $\lim_{x \to p} f(x) = f(p)$).*

* **Global Topological Characterization:**
    A function $f$ is continuous on $X$ **if and only if** the inverse image of every open set is open.
    $$V \text{ is open in } Y \implies f^{-1}(V) \text{ is open in } X$$

* **Continuity & Compactness (Extreme Value Theorem):**
    Continuous maps preserve compactness.
    * If $K \subset X$ is **compact** and $f$ is continuous $\implies f(K)$ is **compact**.
    * *Consequence:* If $f: K \to \mathbb{R}$, $f$ is bounded and attains its Maximum and Minimum.

* **Continuity & Connectedness (Intermediate Value Theorem):**
    Continuous maps preserve connectedness.
    * If $E \subset \mathbb{R}$ is an interval (connected) and $f$ is continuous $\implies f(E)$ is an interval.
    * *Consequence:* $f$ assumes every value between $f(a)$ and $f(b)$.

---

### **3. Uniform Continuity**
Strengthening continuity by removing the dependence of $\delta$ on the point $p$.

* **The Distinction:**
    * **Continuity:** $\delta$ depends on $\epsilon$ **and** $p$. ($\delta(\epsilon, p)$)
    * **Uniform Continuity:** $\delta$ depends **only** on $\epsilon$. ($\delta(\epsilon)$)

* **Definition:**
    $f: E \to Y$ is uniformly continuous if:
    $$\forall \epsilon > 0, \exists \delta > 0 \text{ s.t. } \forall p, q \in E, \quad d_X(p, q) < \delta \implies d_Y(f(p), f(q)) < \epsilon$$

* **The Uniform Continuity Theorem:**
    If $f$ is continuous and the domain $K$ is **compact**, then $f$ is **uniformly continuous** on $K$.
    *(Compactness forces local continuity to become global).*

---

### **4. Discontinuities and Monotonicity**
Analyzing how and where functions fail to be continuous.

* **One-Sided Limits:**
    * $f(p+) = \lim_{x \to p, x>p} f(x)$
    * $f(p-) = \lim_{x \to p, x<p} f(x)$
    * $f$ is continuous at $p \iff f(p+) = f(p-) = f(p)$.

* **Classification of Discontinuities:**
    1.  **Simple (1st Kind):** Both $f(p+)$ and $f(p-)$ exist but differ (Jump), or equal each other but not $f(p)$ (Removable).
    2.  **Second Kind:** At least one of $f(p+)$ or $f(p-)$ does not exist (e.g., infinite oscillation).

* **Monotone Functions:**
    If $f$ is monotone on $(a, b)$:
    1.  **Existence:** Left and right limits exist at every point.
        $$f(p-) \le f(p) \le f(p+)$$
    2.  **Discontinuities:** $f$ has no discontinuities of the second kind. The set of discontinuities is **at most countable**.

* **Inverse Function Theorem:**
    If $f$ is continuous and strictly monotone on an interval $I$, then the inverse $f^{-1}$ is continuous and strictly monotone on the interval $f(I)$.

---

### **Summary of Implications**

$$\text{Differentiable} \implies \text{Lipschitz} \implies \text{Uniformly Continuous} \implies \text{Continuous}$$
*(Note: Reverse implications are generally false without additional assumptions like compactness).*