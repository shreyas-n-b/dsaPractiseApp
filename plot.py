import pandas as pd
import matplotlib.pyplot as plt
import os

# -------------------------------------------------------
# Plot one algorithm (bubble, merge, quick)
# -------------------------------------------------------
def plot_algorithm(algo_name):
    csv_path = f"results/{algo_name}_summary.csv"
    
    if not os.path.exists(csv_path):
        print(f"CSV file not found for {algo_name}: {csv_path}")
        return
    
    # Load CSV
    df = pd.read_csv(csv_path)

    # ------------------------------------------
    # Add smoothing (moving average)
    # ------------------------------------------
    df["smooth"] = df["avg_time_ms"].rolling(window=5).mean()

    # Create plot
    plt.figure(figsize=(9, 5))

    # Raw data (faint line)
    plt.plot(df["n"], df["avg_time_ms"], alpha=0.3, label=f"{algo_name} raw")

    # Smoothed data
    plt.plot(df["n"], df["smooth"], linewidth=2, label=f"{algo_name} smooth")

    # Labels and title
    plt.xlabel("Input Size (n)")
    plt.ylabel("Average Time (ms)")
    plt.title(f"{algo_name.capitalize()} Sort Performance")
    plt.grid(True)
    plt.legend()

    # Save file
    os.makedirs("results/plots", exist_ok=True)
    out_path = f"results/plots/{algo_name}_plot.png"
    plt.savefig(out_path)

    print(f"Plot saved: {out_path}")


# -------------------------------------------------------
# Generate plots for all algorithms
# -------------------------------------------------------
if __name__ == "__main__":
    algorithms = ["bubble", "merge", "quick"]

    for algo in algorithms:
        plot_algorithm(algo)

    print("All plots generated!")
