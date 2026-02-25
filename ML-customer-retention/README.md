# Customer Retention Prediction (Machine Learning)

## Completed as part of graduate-level machine learning project

## Overview
This project analyzes customer retention behavior in a subscription-based service using supervised machine learning. The objective is to identify key factors associated with customer retention and evaluate multiple classification models to determine the most appropriate predictive approach.

The analysis emphasizes interpretability, model comparison, and validation rather than maximizing complexity.

---

## Data Description
The dataset contains customer demographic, behavioral, and billing information, including:
- account tenure
- monthly and total charges
- subscription type
- engagement metrics (e.g., viewing hours)
- customer support interactions

The target variable is **Retention**, derived from the original churn indicator.

Raw data is stored in `data/raw/`, and all preprocessing steps are performed within the notebook to ensure reproducibility.

---

## Exploratory Data Analysis
Exploratory analysis revealed clear patterns related to customer retention:
- Longer account tenure is strongly associated with retention
- Higher engagement (viewing hours and duration) corresponds to higher retention
- Pricing and billing factors show secondary but meaningful effects

Key EDA visualizations are saved in `results/figures/`.

---

## Data Preprocessing
Preprocessing steps included:
- Handling missing values using feature-appropriate strategies
- Encoding categorical variables using one-hot encoding
- Standardizing numeric features
- Removing identifiers prior to modeling
- Creating a binary retention target variable

Class imbalance was addressed through stratified sampling during train–test splitting.

---

## Modeling Approach
Three classification models were evaluated:

- **Logistic Regression** (baseline, interpretable)
- **Decision Tree** (non-linear structure)
- **Random Forest** (ensemble-based)

Models were compared using:
- Accuracy
- Precision
- Recall
- ROC–AUC

---

## Model Comparison
Logistic regression achieved the highest ROC–AUC among the evaluated models, indicating superior discrimination between retained and non-retained customers. While the random forest model achieved very high recall, it did not improve overall ROC–AUC performance relative to the simpler baseline.

A summary of model performance is saved in `results/model_performance_summary.csv`.

---

## Model Validation
To assess model stability, logistic regression was evaluated using 5-fold stratified cross-validation. Cross-validated ROC–AUC values were consistent with hold-out test performance, suggesting that results are stable across different data partitions.

---

## Key Findings
- Customer retention is primarily driven by tenure and engagement
- Pricing and billing factors contribute to retention risk but are secondary
- Increased model complexity did not improve predictive performance
- Logistic regression provides the best balance of performance and interpretability

---

## Limitations
- Observational data limits causal interpretation
- Moderate class imbalance may influence recall-focused metrics
- Feature scope excludes external factors such as marketing exposure or competitor behavior
- Results are based on a single dataset and may not generalize universally

---

## Future Work
- Incorporate additional behavioral and satisfaction data
- Explore cost-sensitive evaluation strategies
- Validate the modeling framework on additional datasets
- Extend the model toward decision-support applications

---

## Repository Structure 


