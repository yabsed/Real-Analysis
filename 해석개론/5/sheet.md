Here is a concise, comprehensive cheat sheet covering Chapters 5.1, 5.2, and 5.3 based on the provided documents.

---

# **Calculus Cheat Sheet: Derivatives & Mean Value Theorems**

## **5.1 The Derivative**

### **1. Definitions**
* **The Derivative:** For $f: I \to \mathbb{R}$ and $p \in I$:
    $$f'(p) = \lim_{x \to p} \frac{f(x) - f(p)}{x - p} = \lim_{h \to 0} \frac{f(p+h) - f(p)}{h}$$
* **One-Sided Derivatives:**
    * **Right:** $f'_+(p) = \lim_{h \to 0^+} \frac{f(p+h) - f(p)}{h}$
    * **Left:** $f'_-(p) = \lim_{h \to 0^-} \frac{f(p+h) - f(p)}{h}$
* **Existence:** $f'(p)$ exists $\iff f'_+(p)$ and $f'_-(p)$ exist and are **equal**.

### **2. Analyzed Functions (Examples)**
* **Power ($f(x)=x^n$):** $f'(x) = nx^{n-1}$.
* **Square Root ($f(x)=\sqrt{x}, x>0$):** Uses rationalization. $f'(x) = \frac{1}{2\sqrt{x}}$.
* **Sine ($f(x)=\sin x$):** Uses $\sin(A+B)$. $f'(x) = \cos x$.
* **Absolute Value ($f(x)=|x|$ at $x=0$):**
    * $f'_+(0) = 1$, $f'_-(0) = -1$.
    * **Result:** Not differentiable at 0.
* **Cusp ($g(x)=x^{3/2}$ at $x=0$):**
    * $g'(0) = \lim_{h \to 0^+} \sqrt{h} = 0$. Differentiable.
* **Oscillating Discontinuity ($f(x) = x \sin(1/x)$ at $x=0$):**
    * Limit oscillates. **Result:** Not differentiable at 0.
* **Diff. with Discontinuous Derivative ($g(x) = x^2 \sin(1/x)$ at $x=0$):**
    * $g'(0) = 0$ (via Squeeze Thm).
    * For $x \neq 0$, $g'(x) = 2x \sin(1/x) - \cos(1/x)$.
    * **Result:** $\lim_{x \to 0} g'(x)$ DNE. $g$ is differentiable, but $g'$ is **discontinuous** at 0.

### **3. Theorems & Arithmetic**
* **Diff $\implies$ Cont:** If $f'(p)$ exists, $f$ is continuous at $p$. (Converse is **False**).
* **Product Rule:** $(fg)' = f'g + fg'$. (Proof uses "add/subtract $f(x+h)g(x)$" trick).
* **Reciprocal Rule:** $(1/g)' = -g' / g^2$.
* **Quotient Rule:** $(f/g)' = (f'g - fg') / g^2$.
* **Chain Rule:** If $h = g \circ f$, then $h'(x) = g'(f(x)) \cdot f'(x)$.
    * *Example:* $h(x) = \sin(1/x^2) \implies h'(x) = \cos(1/x^2) \cdot (-2x^{-3})$.

---

## **5.2 The Mean Value Theorem (MVT)**

### **1. Local Extrema**
* **Theorem:** If $f$ has a local extremum at interior point $p$ and $f'(p)$ exists, then **$f'(p) = 0$**.
* **Corollary:** On $[a, b]$, extrema occur where $f'=0$, $f'$ DNE, or at endpoints.

### **2. Core Theorems**
* **Rolle's Theorem:**
    * **Hypotheses:** Continuous on $[a, b]$, Differentiable on $(a, b)$, **$f(a) = f(b)$**.
    * **Conclusion:** $\exists c \in (a, b)$ such that **$f'(c) = 0$**.
* **Mean Value Theorem (Lagrange):**
    * **Hypotheses:** Continuous on $[a, b]$, Differentiable on $(a, b)$.
    * **Conclusion:** $\exists c \in (a, b)$ such that $f(b) - f(a) = f'(c)(b-a)$.
    * *Example Application:* Prove $\frac{x}{1+x} \le \ln(1+x) \le x$ for $x > -1$.
        * Apply MVT to $\ln(1+t)$ on $[0, x]$. $f'(c) = \frac{1}{1+c}$. Analyze bounds of $c$.
* **Cauchy MVT:**
    * $\frac{f(b)-f(a)}{g(b)-g(a)} = \frac{f'(c)}{g'(c)}$ (assuming $g' \neq 0$).

### **3. Monotonicity & Subtle Pathologies**
* **Standard Rule:**
    * $f' \ge 0$ on $I \implies$ Increasing.
    * $f' = 0$ on $I \implies$ Constant.
* **Pointwise vs. Neighborhood (Crucial):**
    * $f'(c) > 0$ **does NOT** imply $f$ is increasing on a neighborhood $(c-\delta, c+\delta)$.
    * **Counter-Example:** $f(x) = x + 2x^2 \sin(1/x)$ at $x=0$.
        * $f'(0)=1 > 0$, but $f'$ oscillates signs near 0.
    * **Continuous Derivative:** If $f'(c) > 0$ **and** $f'$ is continuous at $c$, *then* $f$ is increasing near $c$.
* **First Derivative Test Converse Error:**
    * Relative min at $c$ **does NOT** imply $f$ is decreasing to the left and increasing to the right.
    * **Counter-Example:** $f(x) = x^4(2+\sin(1/x))$. Absolute min at 0, but oscillates (not monotone) near 0.

### **4. Derivative Properties**
* **Limits of Derivatives:** If $\lim_{x \to a^+} f'(x) = L$, then $f'_+(a) = L$. (Derivatives cannot have simple jump discontinuities).
* **Darboux's Theorem (IVT for Derivatives):** If $f$ is differentiable, $f'$ satisfies the Intermediate Value Property (even if discontinuous).
* **Inverse Function Thm:** If $f' \neq 0$, $(f^{-1})'(y) = \frac{1}{f'(x)}$.

---

## **5.3 L'Hospital's Rule**

### **1. Theorem Statement**
Given $f, g$ differentiable on $(a, b)$, $g' \neq 0$:
If $\lim_{x \to a} \frac{f'(x)}{g'(x)} = L$ AND one of the following holds:
1.  **Case $0/0$:** $\lim f(x) = 0$ and $\lim g(x) = 0$.
2.  **Case $\infty/\infty$:** $\lim g(x) = \pm \infty$.

Then: **$\lim_{x \to a} \frac{f(x)}{g(x)} = L$**

### **2. Proof Concepts**
* **$0/0$ Case:** Uses **Cauchy MVT** on $[a, x]$. Define $f(a)=g(a)=0$.
* **$\infty/\infty$ Case:** Uses MVT + Bounding argument. Does not require continuity at $a$.

### **3. Worked Examples**
* **A. Basic ($0/0$):**
    $$\lim_{x \to 0^+} \frac{\ln(1+x)}{x} \xrightarrow{L'H} \lim_{x \to 0^+} \frac{1/(1+x)}{1} = 1$$
* **B. Repeated Use ($0/0$):**
    $$\lim_{x \to 0} \frac{1 - \cos x}{x^2} \xrightarrow{L'H} \lim_{x \to 0} \frac{\sin x}{2x} \xrightarrow{L'H} \lim_{x \to 0} \frac{\cos x}{2} = \frac{1}{2}$$
* **C. Substitution Required:**
    * **Problem:** $\lim_{x \to 0^+} \frac{e^{-1/x}}{x}$. Direct differentiation fails (gets messier).
    * **Fix:** Let $t = 1/x$. As $x \to 0^+, t \to \infty$.
    * **New Limit:** $\lim_{t \to \infty} \frac{t}{e^t}$ (Case $\infty/\infty$).
    * **Apply L'H:** $\lim \frac{1}{e^t} = 0$.