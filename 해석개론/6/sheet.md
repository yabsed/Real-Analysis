Here is a comprehensive cheat sheet for Chapter 6 (The Riemann Integral), covering Sections 6.1 through 6.5.

---

### **6.1 The Riemann Integral**

**1. Definitions**
* **Partition $\mathcal{P}$:** A set $\{x_0, \dots, x_n\}$ where $a = x_0 < \dots < x_n = b$.
* **Bounds:** On subinterval $[x_{i-1}, x_i]$:
    * $m_i = \inf f(x)$
    * $M_i = \sup f(x)$
* **Sums:**
    * Lower Sum: $\mathcal{L}(\mathcal{P}, f) = \sum m_i \Delta x_i$
    * Upper Sum: $\mathcal{U}(\mathcal{P}, f) = \sum M_i \Delta x_i$
* **Inequality:** $\mathcal{L}(\mathcal{P}, f) \le \underline{\int} f \le \overline{\int} f \le \mathcal{U}(\mathcal{P}, f)$

**2. Riemann Integrability ($f \in \mathcal{R}[a, b]$)**
* **Definition:** $f$ is integrable if Upper Integral = Lower Integral.
    $$\overline{\int_a^b} f = \inf_{\mathcal{P}} \mathcal{U}(\mathcal{P}, f) = \sup_{\mathcal{P}} \mathcal{L}(\mathcal{P}, f) = \underline{\int_a^b} f$$
* **Riemann’s Criterion (Key for Proofs):**
    $f \in \mathcal{R}[a, b] \iff \forall \epsilon > 0, \exists \mathcal{P}$ such that:
    $$\mathcal{U}(\mathcal{P}, f) - \mathcal{L}(\mathcal{P}, f) < \epsilon$$

**3. Integrable Classes**
* **Continuous Functions:** Integrable (proof uses Uniform Continuity).
* **Monotone Functions:** Integrable (proof uses telescoping sum).
* **Composition Theorem:** If $f \in \mathcal{R}$ and $\varphi$ is continuous, then $\varphi \circ f \in \mathcal{R}$.
    * *Corollary:* If $f \in \mathcal{R}$, then $|f| \in \mathcal{R}$ and $f^2 \in \mathcal{R}$.

**4. Lebesgue’s Theorem**
* **Measure Zero:** Set $E$ covers by intervals with total length $< \epsilon$. (e.g., Finite sets, $\mathbb{Q}$, Cantor set).
* **Theorem:** $f \in \mathcal{R} \iff$ The set of discontinuities of $f$ has measure zero.

**5. Classical Examples**
* **Dirichlet Function:** $f(x)=1$ if $x \in \mathbb{Q}$, $0$ else.
    * $m_i = 0, M_i = 1 \implies \mathcal{L}=0, \mathcal{U}=b-a$. **Not Integrable.**
* **Thomae’s Function:** $f(x)=1/n$ if $x=m/n$, $0$ irrational.
    * Discontinuous only at $\mathbb{Q}$ (measure 0). **Integrable**, $\int f = 0$.

---

### **6.2 Properties of the Integral**

**1. Algebraic Properties**
If $f, g \in \mathcal{R}[a, b]$:
* **Linearity:** $\int (cf + g) = c\int f + \int g$.
* **Product:** $fg \in \mathcal{R}$.
* **Additivity:** $\int_a^b f = \int_a^c f + \int_c^b f$ for $a < c < b$.

**2. Order Properties**
* **Positivity:** If $f(x) \ge 0$, then $\int f \ge 0$.
* **Comparison:** If $f \le g$, then $\int f \le \int g$.
* **Absolute Value Inequality:**
    $$\left| \int_a^b f(x) \, dx \right| \le \int_a^b |f(x)| \, dx$$

**3. Riemann Sums (Equivalence)**
* **Tagged Sum:** $S(\mathcal{P}, f) = \sum f(t_i) \Delta x_i$ where $t_i \in [x_{i-1}, x_i]$.
* **Theorem:** Darboux integrability $\iff \lim_{||\mathcal{P}|| \to 0} S(\mathcal{P}, f)$ exists.
* **Example:** $\int_a^b x \, dx = \frac{b^2 - a^2}{2}$ via midpoint tags $t_i = \frac{x_i + x_{i-1}}{2}$.

---

### **6.3 Fundamental Theorem of Calculus (FTC)**

**1. FTC Part 1 (Evaluation)**
If $f \in \mathcal{R}$ and $F$ is an antiderivative ($F' = f$):
$$\int_a^b f(x) \, dx = F(b) - F(a)$$
* *Proof:* Use MVT on subintervals: $F(x_i) - F(x_{i-1}) = f(t_i)\Delta x_i$. Sum telescopically.

**2. FTC Part 2 (Differentiation)**
If $f \in \mathcal{R}$ and $F(x) = \int_a^x f(t) \, dt$:
* $F$ is continuous on $[a, b]$.
* If $f$ is continuous at $c$, then $F$ is differentiable at $c$ and **$F'(c) = f(c)$**.

**3. Integration Techniques**
* **Integration by Parts:** $\int_a^b f g' = [fg]_a^b - \int_a^b g f'$.
* **Substitution (Change of Variable):** $\int_a^b f(\varphi(t)) \varphi'(t) \, dt = \int_{\varphi(a)}^{\varphi(b)} f(x) \, dx$.
* **MVT for Integrals:** If $f$ continuous, $\exists c$ such that $\int_a^b f = f(c)(b-a)$.

**4. The Natural Logarithm**
* **Definition:** $L(x) = \int_1^x \frac{1}{t} \, dt$.
* **Properties:** $L(ab) = L(a) + L(b)$, $L'(x) = 1/x$, $L(e)=1$.

---

### **6.4 Improper Riemann Integrals**

**1. Definitions**
* **Unbounded Interval:** $\int_a^\infty f = \lim_{c \to \infty} \int_a^c f$.
* **Singularity (at $a$):** $\int_a^b f = \lim_{c \to a^+} \int_c^b f$.
* **Note:** Properties of standard Riemann integral (e.g., $f \in \mathcal{R} \implies f^2 \in \mathcal{R}$) **fail** here.

**2. Comparison Test**
If $|f(x)| \le g(x)$ and $\int g$ converges, then $\int f$ converges (Absolute Integrability).

**3. Key Examples**
* **$1/x$ on $(0, 1]$:** Diverges ($\ln c \to \infty$).
* **$\ln x$ on $(0, 1]$:** Converges to $-1$ (Integration by parts).
* **$1/x^2$ on $[1, \infty)$:** Converges to $1$.
* **$\sin x / x$ on $[\pi, \infty)$:** Conditionally convergent (integral exists, but $\int |\frac{\sin x}{x}|$ diverges due to Harmonic series).
* **Counter-Example:** $f(x) = 1/\sqrt{x}$ converges on $(0,1]$, but $f^2(x) = 1/x$ diverges.

---

### **6.5 The Riemann-Stieltjes Integral**

**1. Definition**
Integrate $f$ with respect to monotone increasing $\alpha$: $\int_a^b f \, d\alpha$.
* **Sums:** $\mathcal{U}(\mathcal{P}, f, \alpha) = \sum M_i \Delta \alpha_i$ where $\Delta \alpha_i = \alpha(x_i) - \alpha(x_{i-1})$.
* **Condition:** $\int f d\alpha$ exists if $\inf \mathcal{U} = \sup \mathcal{L}$.

**2. Calculation Methods (Reductions)**
* **If $\alpha$ is Differentiable:**
    $$\int_a^b f(x) \, d\alpha(x) = \int_a^b f(x) \alpha'(x) \, dx$$
* **If $\alpha$ is a Step Function:** (Jumps at $s_n$ with height $c_n$)
    $$\int_a^b f \, d\alpha = \sum c_n f(s_n)$$
    *(Requires $f$ continuous at $s_n$)*.

**3. Integration by Parts (Stieltjes)**
$$\int_a^b \alpha \, d\beta = [\alpha \beta]_a^b - \int_a^b \beta \, d\alpha$$

**4. Key Examples**
* **Unit Jump:** $\alpha = I_c(x)$ (jump at $c$). $\int f \, dI_c = f(c)$.
* **Dirichlet:** If $f$ is Dirichlet and $\alpha(x)=x$, **not** integrable.