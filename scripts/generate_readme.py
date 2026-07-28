from pathlib import Path
from datetime import datetime

root = Path(".")

folders = []

for item in root.iterdir():
    if item.is_dir() and item.name[:4].isdigit():
        files = sorted(
            [
                f.stem
                for f in item.iterdir()
                if f.is_file()
                and f.suffix in [".cpp", ".java", ".py", ".c", ".js", ".ts"]
            ]
        )

        folders.append(
            {
                "date": item.name,
                "count": len(files),
                "files": files,
            }
        )

folders.sort(key=lambda x: x["date"], reverse=True)

total_questions = sum(x["count"] for x in folders)
total_days = len(folders)

lines = []

lines.append("# 🚀 DSA Practice\n")

lines.append("## 📊 Stats\n")
lines.append(f"- Total Days Practiced: **{total_days}**")
lines.append(f"- Total Questions Solved: **{total_questions}**")
lines.append(f"- Last Updated: **{datetime.now().strftime('%Y-%m-%d %H:%M')}**\n")

lines.append("---\n")
lines.append("## 📅 Daily Progress\n")

lines.append("| Date | Questions | Count |")
lines.append("|------|-----------|------:|")

for folder in folders:
    questions = ", ".join(folder["files"])
    lines.append(
        f"| {folder['date']} | {questions} | {folder['count']} |"
    )

lines.append("\n---")

Path("README.md").write_text("\n".join(lines), encoding="utf-8")
