"""HTML format articles exporter.

Provide an HTML output for articles list.
"""
from article import Article
from typing import List


class HtmlArticlesExporter:
    """HTML format articles exporter."""

    def __init__(self, articles: List[Article] = []):
        """Init articles list."""
        self.__articles: List[Article] = articles

    def export(self, file_path: str = "output.html"):
        """Export HTML in output file."""
        output_file = open(file_path, "w")
        output_file.truncate(0)

        # Write HTML header
        output_file.write('<!DOCTYPE html>\n')
        output_file.write('<html lang="fr">\n')
        output_file.write('\t<head>\n')
        output_file.write('\t\t<title>Articles</title>\n')
        output_file.write('\t\t<meta charset="utf-8">\n')
        output_file.write('\t\t<meta name="viewport" '
                          'content="width=device-width, initial-scale=1">\n')
        output_file.write('\t\t<link rel="stylesheet" '
                          'href="https://maxcdn.bootstrapcdn.com/bootstrap/'
                          '4.3.1/css/bootstrap.min.css">\n')
        output_file.write('\t\t<script src="https://ajax.googleapis.com/ajax/'
                          'libs/jquery/3.4.1/jquery.min.js"></script>\n')
        output_file.write('\t\t<script src="https://cdnjs.cloudflare.com/ajax/'
                          'libs/popper.js/1.14.7/umd/popper.min.js"></script>'
                          '\n')
        output_file.write('\t\t<script src="https://maxcdn.bootstrapcdn.com/'
                          'bootstrap/4.3.1/js/bootstrap.min.js"></script>\n')
        output_file.write('\t</head>\n')
        output_file.write('\t<body>\n')
        output_file.write('\t\t<div class="jumbotron text-center">\n')
        output_file.write('\t\t\t<h1>Articles</h1>\n')
        output_file.write('\t\t\t<p>Custom articles export</p>\n')
        output_file.write('\t\t</div>\n')

        # Loop articles and write them
        output_file.write('\t\t<div class="container">\n\n')
        for article in self.__articles:
            output_file.write('\t\t\t<h4>'+str(article.getTitle())+'</h4>\n')
            output_file.write('\t\t\t<h5>'+str(article.getDate())+'</h5>\n')
            output_file.write('\t\t\t<p>'+str(article.getDescription())+''
                              '</p>\n\n')

        # Write HTML footer
        output_file.write('\t\t</div>\n')
        output_file.write('\t</body>\n')
        output_file.write('</html>\n')

        # Close file
        output_file.close()
