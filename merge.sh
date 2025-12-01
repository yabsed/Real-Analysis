# 1. 하위 디렉토리 재귀 검색 기능 켜기
shopt -s globstar

# 2. 합치기 명령어 실행 (모든 하위 폴더의 pdf를 merged_output.pdf로 합침)
pdfunite **/*.pdf merged_output.pdf