# Codebook Template for Competitive Programming

[![Compile Codebook](https://github.com/Yuankai619/Mashu-Codebook/actions/workflows/check.yml/badge.svg)](https://github.com/Yuankai619/Mashu-Codebook/actions/workflows/check.yml)

![Docker](https://img.shields.io/badge/docker-%230db7ed.svg?style=for-the-badge&logo=docker&logoColor=white)
![GitHub Actions](https://img.shields.io/badge/github%20actions-%232671E5.svg?style=for-the-badge&logo=githubactions&logoColor=white)

Here’s a professional README.md for your project:

---

# Codebook Editor for Competitive Programming

This project provides a 25-page Codebook editing template designed for competitive programmer. It streamlines the process of compiling and formatting a Codebook by automating the LaTeX compilation flow using Docker images and GitHub workflows. This significantly reduces issues related to LaTeX environment setup and font dependencies. With this setup, users only need to focus on editing the content, and by simply pushing changes to GitHub, a fully compiled PDF will automatically be generated.

## Key Features

-   **Automated LaTeX Compilation**: Docker and GitHub Actions are used to automate the LaTeX compilation process.
-   **Cross-Platform Compatibility**: Resolves environment and font dependency issues by encapsulating the LaTeX environment within a Docker container.
-   **Easy Editing**: Focus on editing the content (`content.tex`) of your Codebook. No need to worry about setting up LaTeX locally or managing font dependencies.
-   **Automatic PDF Generation**: Simply push changes to GitHub, and a PDF version of the Codebook is automatically compiled and ready for download.

## Tech Stack

-   **Docker**: Containerizes the LaTeX environment to ensure consistency across different systems.
-   **GitHub Actions**: Automates the build and LaTeX compilation process via GitHub workflows.
-   **LaTeX Environment**: Using the `texlive:latest` Docker image for the LaTeX setup.
-   **Fonts**: Utilizes **Consolas** and **NotoSansCJKtc** for high-quality, readable typography.

## Usage

1. **Fork the Repository**: Begin by forking this repository to your own GitHub account.

2. **Edit the `content.tex` File**: Modify the `content.tex` file to customize the sections and structure of your Codebook. This file controls the presentation of your Codebook and its contents.

3. **Example Usage**: Below is an example of how to structure a section of your Codebook using LaTeX:

    ```latex
    \section{Chapter Title}

    \subsection{Dijkstra's Algorithm} % Displays algorithm name
    \lstinputlisting{graph/Dijkstra.cpp} % Relative path to code file

    \subsection{SPFA Algorithm}
    \lstinputlisting{graph/SPFA.cpp} % Relative path to code file
    ```

4. **Push to GitHub**: After editing the `content.tex` file, push your changes to GitHub. The GitHub Actions workflow will automatically compile the LaTeX document and generate the PDF.

5. **Download PDF**: Once the workflow completes, you can download the compiled PDF from the GitHub Actions workflow artifacts.

## Installation

### Prerequisites

-   **Docker**: Make sure Docker is installed and running on your system to build the LaTeX container.
-   **GitHub Account**: Fork the repository and push your changes to trigger the GitHub Actions workflow.

### Running Locally

While the primary setup relies on GitHub Actions, you can also compile the LaTeX document locally using Docker by running the following commands:

1. pull the Docker image:

    ```bash
    docker pull ghcr.io/yuankai619/codebook:latest
    ```

2. Compile the LaTeX document:

    ```bash
    docker run --rm -v $(pwd):/workspace ghcr.io/yuankai619/codebook:latest bash -c "xelatex codebook.tex && xelatex codebook.tex"
    ```
