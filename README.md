# FAIDX
# Language: C++
# Input: TXT
# Output: FASTA
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: faidx 0.5.9.5

PluMA plugin to take a FASTA file and extra all sequences within a length range using FAIDX (Shirley et al, 2015)

The plugin expects as input a TXT file of tab-delimited keywords and values:
fastafile: File of sequences
lo: Lower length boundary
hi: Upper length boundary

The plugin will then output a FASTA File of all input sequences within the length boundaries.

