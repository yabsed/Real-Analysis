Here is a comprehensive, condensed mathematical cheat sheet based on the provided material.

# **Cheat Sheet: Real Analysis & Series**

## **1. Series of Real Numbers (Fundamentals)**

### **Definitions**
* **Series:** $\sum_{k=1}^{\infty} a_k$. **Partial Sum:** $s_n = \sum_{k=1}^{n} a_k$.
* **Convergence:** $\sum a_k = s \iff \lim_{n \to \infty} s_n = s$.
* **Linearity:** $\sum (c a_k + b_k) = c \sum a_k + \sum b_k$ (if convergent).

### **Comparison Tests (for $a_k \ge 0$)**
1.  **Direct Comparison:** Given $0 \le a_k \le M b_k$:
    * $\sum b_k < \infty \implies \sum a_k < \infty$.
    * $\sum a_k = \infty \implies \sum b_k = \infty$.
2.  **Limit Comparison Test (LCT):** Let $L = \lim_{n \to \infty} \frac{a_n}{b_n}$.
    * $0 < L < \infty$: $\sum a_k \iff \sum b_k$ (Converge/Diverge together).
    * $L = 0$: $\sum b_k < \infty \implies \sum a_k < \infty$.
    * *Example 1:* $\sum \frac{k}{3^k}$ vs $\sum (1/2)^k \implies$ **Converges**.
    * *Example 2:* $\sum \sqrt{\frac{k+1}{2k^3+1}} \approx \sum \frac{1}{k\sqrt{2}} \implies$ **Diverges**.

### **Integral Test**
Let $f(x)$ be continuous, non-negative, decreasing on $[1, \infty)$ where $f(k) = a_k$.
$$\sum_{k=1}^{\infty} a_k < \infty \iff \int_{1}^{\infty} f(x) \, dx < \infty$$
* **p-Series:** $\sum \frac{1}{k^p}$ converges $\iff p > 1$.
* **Log Series:** $\sum \frac{1}{k \ln k}$ diverges ($\int \frac{dx}{x \ln x} = \ln(\ln x) \to \infty$).

### **Root and Ratio Tests**
Let $R = \limsup |\frac{a_{k+1}}{a_k}|$, $r = \liminf |\frac{a_{k+1}}{a_k}|$, and $\alpha = \limsup \sqrt[k]{|a_k|}$.

| Test | Condition | Conclusion | Note |
| :--- | :--- | :--- | :--- |
| **Ratio** | $R < 1$ | **Converges** | Good for factorials. |
| | $r > 1$ | **Diverges** | |
| | $r \le 1 \le R$ | **Inconclusive** | p-series fails here. |
| **Root** | $\alpha < 1$ | **Converges** | **Stronger test.** |
| | $\alpha > 1$ | **Diverges** | |
| | $\alpha = 1$ | **Inconclusive** | |

* **Hierarchy:** Root test is strictly stronger.
    * *Ex:* $a_n$ alternating $1/2^k, 1/3^k$. Ratio oscillates (inconclusive), Root gives $\alpha = 1/\sqrt{2} < 1$ (Converges).

---

## **2. Dirichlet Test & Applications**

### **Abel's Partial Summation Formula**
Discrete analogue of Integration by Parts. Let $A_n = \sum_{i=1}^n a_i$.
$$\sum_{k=p}^{q} a_k b_k = \sum_{k=p}^{q-1} A_k (b_k - b_{k+1}) + A_q b_q - A_{p-1} b_p$$

### **Dirichlet Test**
$\sum a_k b_k$ converges if:
1.  **Bounded Sums:** $|\sum_{k=1}^n a_k| \le M$ for all $n$.
2.  **Monotonic:** $b_1 \ge b_2 \ge \dots \ge 0$.
3.  **Vanishing:** $\lim_{k \to \infty} b_k = 0$.

### **Alternating Series Test (AST)**
Case of Dirichlet where $a_k = (-1)^{k+1}$.
* **Condition:** $b_k \downarrow 0$.
* **Result:** $\sum (-1)^{k+1} b_k$ converges.
* **Error Estimate:** $|S - S_n| \le b_{n+1}$.
    * *Ex:* $\sum \frac{(-1)^{k+1}}{2k-1} \to \frac{\pi}{4}$. Very slow convergence (need $n \approx 50$ for 0.01 accuracy).

### **Trigonometric Series**
1.  **Sine:** $\sum b_k \sin(kt)$ converges $\forall t \in \mathbb{R}$ (if $b_k \downarrow 0$).
2.  **Cosine:** $\sum b_k \cos(kt)$ converges $\forall t \in \mathbb{R} \setminus \{2p\pi\}$.
    * *Reason:* Partial sums of $\sin(kt)$ and $\cos(kt)$ are bounded by $\csc(t/2)$ unless $t=2p\pi$.
    * *Ex:* $\sum \frac{1}{k} \cos(kt)$ diverges at $t=0$ (Harmonic) but converges elsewhere.

---

## **3. Absolute vs. Conditional Convergence**

### **Definitions**
* **Absolute Convergence:** $\sum |a_k| < \infty$. Implies convergence ($\sum a_k < \infty$).
* **Conditional Convergence:** $\sum a_k < \infty$ BUT $\sum |a_k| = \infty$.
    * *Ex:* $\sum \frac{(-1)^{k+1}}{k}$ (Alternating Harmonic).

### **Rearrangements**
* **Absolutely Convergent:** Any rearrangement sums to the same value.
* **Conditionally Convergent (Riemann's Theorem):** Can be rearranged to converge to **any** $\alpha \in \mathbb{R}$ or diverge to $\pm \infty$.
    * *Mechanism:* Greedy algorithm taking enough positive terms to exceed $\alpha$, then negative terms to drop below, repeating indefinitely.

---

## **4. The Space $l^2$ (Square Summable Sequences)**

### **Structure**
* **Definition:** $l^2 = \{ \{a_k\} : \sum a_k^2 < \infty \}$.
* **Norm:** $||a||_2 = \sqrt{\sum_{k=1}^{\infty} a_k^2}$.
* **Convergence Examples:**
    * $\{1/k\} \in l^2$ ($\sum 1/k^2 < \infty$).
    * $\{1/\sqrt{k}\} \notin l^2$ ($\sum 1/k = \infty$).
    * $\{1/k^q\} \in l^2 \iff q > 1/2$ (since $\sum 1/k^{2q}$ requires $2q > 1$).

### **Inequalities**
1.  **Cauchy-Schwarz:** Fundamental for geometry/angles.
    $$\sum |a_k b_k| \le ||a||_2 \cdot ||b||_2$$
    * *Implication:* Inner product $\langle a,b \rangle = \sum a_k b_k$ is well-defined.
2.  **Minkowski (Triangle Inequality):**
    $$||a + b||_2 \le ||a||_2 + ||b||_2$$
    * *Proof:* Uses Cauchy-Schwarz on expanded square $(a_k+b_k)^2$.

### **Normed Linear Spaces**
$l^2$ is a vector space with a norm satisfying:
1.  **Non-negativity:** $||x|| \ge 0$, equals 0 iff $x=0$.
2.  **Homogeneity:** $||cx|| = |c| \cdot ||x||$.
3.  **Triangle Inequality:** $||x+y|| \le ||x|| + ||y||$.

* **Metric:** $d(x,y) = ||x-y||$.
* **Convergence:** $x_n \to x$ in $l^2 \iff ||x_n - x||_2 \to 0$.