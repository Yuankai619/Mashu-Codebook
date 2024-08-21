FROM ubuntu:latest

RUN apt-get update
RUN apt install --no-install-recommends texlive-full -y

RUN apt-get install -y wget fontconfig unzip git
RUN mkdir -p /usr/share/fonts/truetype/consolas && \
    wget https://github.com/kakkoyun/linux.files/raw/master/fonts/Consolas.ttf -O /usr/share/fonts/truetype/consolas/Consolas.ttf && \
    chmod 644 /usr/share/fonts/truetype/consolas/Consolas.ttf && \
    fc-cache -fv

RUN wget https://noto-website.storage.googleapis.com/pkgs/NotoSansCJKtc-hinted.zip -O /usr/share/fonts/NotoSansCJKtc-hinted.zip && \
    unzip /usr/share/fonts/NotoSansCJKtc-hinted.zip -d /usr/share/fonts/NotoSansCJKtc/ && \
    chmod 644 /usr/share/fonts/NotoSansCJKtc/*.otf && \
    fc-cache -fv

RUN rm /usr/share/fonts/NotoSansCJKtc-hinted.zip

WORKDIR /codebook

RUN git clone https://github.com/Yuankai619/Mashu-Codebook.git
WORKDIR /codebook/Mashu-Codebook
RUN xelatex codebook.tex
RUN xelatex codebook.tex
ENTRYPOINT [ "ls" ]